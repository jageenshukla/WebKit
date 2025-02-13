/*
 * Copyright (C) 2022 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include <wtf/Seconds.h>

namespace WebCore::PCM {

struct AttributionSecondsUntilSendData {
    std::optional<Seconds> sourceSeconds;
    std::optional<Seconds> destinationSeconds;

    bool hasValidSecondsUntilSendValues()
    {
        return sourceSeconds && destinationSeconds;
    }

    std::optional<Seconds> minSecondsUntilSend()
    {
        if (!sourceSeconds && !destinationSeconds)
            return std::nullopt;

        if (sourceSeconds && destinationSeconds)
            return std::min(sourceSeconds, destinationSeconds);

        return sourceSeconds ? sourceSeconds : destinationSeconds;
    }

    template<class Encoder>
    void encode(Encoder& encoder) const
    {
        encoder << sourceSeconds << destinationSeconds;
    }

    template<class Decoder>
    static std::optional<AttributionSecondsUntilSendData> decode(Decoder& decoder)
    {
        std::optional<std::optional<Seconds>> sourceSeconds;
        decoder >> sourceSeconds;
        if (!sourceSeconds)
            return std::nullopt;

        std::optional<std::optional<Seconds>> destinationSeconds;
        decoder >> destinationSeconds;
        if (!destinationSeconds)
            return std::nullopt;

        return AttributionSecondsUntilSendData { WTFMove(*sourceSeconds), WTFMove(*destinationSeconds) };
    }
};


}
