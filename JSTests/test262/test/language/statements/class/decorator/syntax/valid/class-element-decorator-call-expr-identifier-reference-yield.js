// This file was procedurally generated from the following sources:
// - src/decorator/decorator-call-expr-identifier-reference-yield.case
// - src/decorator/syntax/valid/cls-element-decorators-valid-syntax.template
/*---
description: Decorator @ DecoratorCallExpression (Valid syntax for decorator on class.)
esid: prod-ClassDeclaration
features: [class, decorators]
flags: [generated, noStrict]
info: |
    ClassElement[Yield, Await] :
      DecoratorList[?Yield, ?Await]opt MethodDefinition[?Yield, ?Await]
      DecoratorList[?Yield, ?Await]opt static MethodDefinition[?Yield, ?Await]
      DecoratorList[?Yield, ?Await]opt FieldDefinition[?Yield, ?Await] ;
      DecoratorList[?Yield, ?Await]opt static FieldDefinition[?Yield, ?Await] ;
      ClassStaticBlock
      ;

    DecoratorList[Yield, Await] :
      DecoratorList[?Yield, ?Await]opt Decorator[?Yield, ?Await]

    Decorator[Yield, Await] :
      @ DecoratorMemberExpression[?Yield, ?Await]
      @ DecoratorParenthesizedExpression[?Yield, ?Await]
      @ DecoratorCallExpression[?Yield, ?Await]

    ...


    DecoratorCallExpression[Yield, Await] :
      DecoratorMemberExpression[?Yield, ?Await] Arguments[?Yield, ?Await]

    DecoratorMemberExpression[Yield, Await] :
      IdentifierReference[?Yield, ?Await]
      PrivateIdentifier
      DecoratorMemberExpression[?Yield, ?Await] . IdentifierName

    IdentifierReference[Yield, Await] :
      [~Yield] yield
      ...

---*/
function decorator() {
  return () => {};
}
var yield = decorator;



class C {
  @yield() method() {}
  @yield() static method() {}
  @yield() field;
  @yield() static field;
}
