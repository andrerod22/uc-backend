"""
ucexpr.py.

This file contains definitions of AST nodes that represent uC
expressions.

Project UID c49e54971d13f14fbc634d7a0fe4b38d421279e7
"""

from dataclasses import dataclass
from typing import List, Optional
from ucbase import attribute
import ucbase
from ucerror import error
import ucfunctions
import uctypes
import pdb

#############################
# Base Node for Expressions #
#############################

@dataclass
class ExpressionNode(ucbase.ASTNode):
    """The base class for all nodes representing expressions.

    type is a reference to the computed uctypes.Type of this
    expression.
    """

    type: Optional[uctypes.Type] = attribute()

    def is_lvalue(self):
        """Return whether or not this node produces an l-value."""
        return False

    # add your code below if necessary


############
# Literals #
############

@dataclass
class LiteralNode(ExpressionNode):
    """The base class for all nodes representing literals.

    text is the textual representation of the literal for code
    generation.
    """

    text: str

    # add your code below if necessary


@dataclass
class IntegerNode(LiteralNode):
    """An AST node representing an integer (int or long) literal."""

    # add your code below
    def gen_function_defs(self, ctx):
        """Generate function definitions for the statements in this block."""
        return f'{self.text}'


@dataclass
class FloatNode(LiteralNode):
    """An AST node representing a float literal."""

    # add your code below


@dataclass
class StringNode(LiteralNode):
    """An AST node representing a string literal."""

    # add your code below


@dataclass
class BooleanNode(LiteralNode):
    """An AST node representing a boolean literal."""

    # add your code below


@dataclass
class NullNode(LiteralNode):
    """An AST node representing the null literal."""

    text: str = 'nullptr'

    # add your code below
    def gen_function_defs(self, ctx):
        """Generate function definitions for the statements in this block."""
        return f'{self.text}'


###################
# Name Expression #
###################

@dataclass
class NameExpressionNode(ExpressionNode):
    """An AST node representing a name expression.

    name is an AST node denoting the actual name.
    """

    name: ucbase.NameNode

    # add your code below
    def gen_function_defs(self, ctx):
        """Generate function definitions for the statements in this block."""
        return f'UC_VAR({self.name.raw})'



#######################
# Calls and Accessors #
#######################

@dataclass
class CallNode(ExpressionNode):
    """An AST node representing a function-call expression.

    name is an AST node representing the name of the function and args
    is a list of argument expressions to the function. func is a
    reference to the ucfunctions.Function named by this call.
    """

    name: ucbase.NameNode
    args: List[ExpressionNode]
    func: Optional[ucfunctions.Function] = attribute()

    # add your code below
    def gen_function_defs(self, ctx):
        """Generate function definitions for the statements in this block."""
        # Generate the mangled function name using the UC_FUNCTION macro
        mangled_function_name = f'UC_FUNCTION({self.name.raw})'

        # Generate the C++ code representations for the arguments
        # breakpoint()
        arg_codes = [arg.gen_function_defs(ctx) for arg in self.args]

        # Combine the arguments with commas
        arg_str = ', '.join(arg_codes)

        # Generate the C++ code for the function call
        return f'{mangled_function_name}({arg_str})'

@dataclass
class NewNode(ExpressionNode):
    """An AST node representing a new expression.

    typename is an AST node representing the type of the object and
    args is a list of argument expressions to the constructor.
    """

    typename: ucbase.BaseTypeNameNode
    args: List[ExpressionNode]

    type: Optional[uctypes.Type] = attribute()
    def resolve_types(self, ctx):
        """Resolve types of NewNode."""
        new_ctx = ctx.clone()
        new_ctx['is_return'] = False
        self.typename.resolve_types(ctx)
        self.type = self.typename.type
        super().resolve_types(ctx)
    
    # add your code below
    def gen_function_defs(self, ctx):
        """Generate function definitions for the statements in this new expression."""
        
        # Generate mangled name for the type:
        mangled_type_name = self.typename.type.mangle()
        
        # Generate the constructor args:

        arg_list = [arg.gen_function_defs(ctx) for arg in self.args]
        
        # Combine args with comma:
        arg_str = ', '.join(arg_list)
        
        # Generate the new expression:
        return f'uc::uc_construct<{mangled_type_name}>({arg_str})'

@dataclass
class FieldAccessNode(ExpressionNode):
    """An AST node representing access to a field of an object.

    receiver is an expression representing the object whose field is
    being accessed and field is is an AST node representing the name
    of the field.
    """

    receiver: ExpressionNode
    field: ucbase.NameNode

    def gen_function_defs(self, ctx):
        """Generate function definitions for the statements in this block."""
        # add your code below
        receiver_code = self.receiver.gen_function_defs(ctx)
        field_name = self.field.raw
        return f'{receiver_code}->UC_VAR({field_name})'



@dataclass
class ArrayIndexNode(ExpressionNode):
    """An AST node representing indexing into an array.

    receiver is an expression representing the array and index the
    index expression.
    """

    receiver: ExpressionNode
    index: ExpressionNode

    # add your code below


#####################
# Unary Expressions #
#####################

@dataclass
class UnaryPrefixNode(ExpressionNode):
    """A base AST node that represents a unary prefix operation.

    expr is the expression to which the operation is being applied and
    op_name is the string representation of the operator.
    """

    expr: ExpressionNode
    op_name: str

    # add your code below if necessary


@dataclass
class PrefixSignNode(UnaryPrefixNode):
    """A base AST node representing a prefix sign operation."""

    # add your code below if necessary


@dataclass
class PrefixPlusNode(PrefixSignNode):
    """An AST node representing a prefix plus operation."""

    op_name: str = '+'

    # add your code below if necessary


@dataclass
class PrefixMinusNode(PrefixSignNode):
    """An AST node representing a prefix minus operation."""

    op_name: str = '-'

    # add your code below if necessary


@dataclass
class NotNode(UnaryPrefixNode):
    """An AST node representing a not operation."""

    op_name: str = '!'

    # add your code below if necessary


@dataclass
class PrefixIncrDecrNode(UnaryPrefixNode):
    """A base AST node representing a prefix {in,de}crement operation."""

    # add your code below if necessary


@dataclass
class PrefixIncrNode(PrefixIncrDecrNode):
    """An AST node representing a prefix increment operation."""

    op_name: str = '++'

    # add your code below if necessary


@dataclass
class PrefixDecrNode(PrefixIncrDecrNode):
    """An AST node representing a prefix decrement operation.

    expr is the operand expression.
    """

    op_name: str = '--'

    # add your code below if necessary


@dataclass
class IDNode(UnaryPrefixNode):
    """An AST node representing an id operation."""

    op_name: str = '#'

    # add your code below if necessary


######################
# Binary Expressions #
######################

# Base classes

@dataclass
class BinaryOpNode(ExpressionNode):
    """A base AST node that represents a binary infix operation.

    lhs is the left-hand side expression, rhs is the right-hand side
    expression, and op_name is the name of the operator.
    """

    lhs: ExpressionNode
    rhs: ExpressionNode
    op_name: str

    # add your code below if necessary


@dataclass
class BinaryArithNode(BinaryOpNode):
    """A base AST node representing a binary arithmetic operation."""

    # add your code below if necessary


@dataclass
class BinaryLogicNode(BinaryOpNode):
    """A base AST node representing a binary logic operation."""

    # add your code below if necessary


@dataclass
class BinaryCompNode(BinaryOpNode):
    """A base AST node representing binary comparison operation."""

    # add your code below if necessary
    def gen_function_defs(self, ctx):
        return f'{self.lhs.gen_function_defs(ctx)} {self.op_name} {self.rhs.gen_function_defs(ctx)}'

@dataclass
class EqualityTestNode(BinaryOpNode):
    """A base AST node representing an equality comparison."""

    # add your code below if necessary
    def gen_function_defs(self, ctx):
        """Generates macros for uc equality expressions"""
        return f'{self.lhs.gen_function_defs(ctx)} {self.op_name} {self.rhs.gen_function_defs(ctx)}'


# Arithmetic operations

@dataclass
class PlusNode(BinaryArithNode):
    """An AST node representing a binary plus operation."""

    op_name: str = '+'

    # add your code below


@dataclass
class MinusNode(BinaryArithNode):
    """An AST node representing a binary minus operation."""

    op_name: str = '-'

    # add your code below if necessary


@dataclass
class TimesNode(BinaryArithNode):
    """An AST node representing a binary times operation."""

    op_name: str = '*'

    # add your code below if necessary


@dataclass
class DivideNode(BinaryArithNode):
    """An AST node representing a binary divide operation."""

    op_name: str = '/'

    # add your code below if necessary


@dataclass
class ModuloNode(BinaryArithNode):
    """An AST node representing a binary modulo operation."""

    op_name: str = '%'

    # add your code below if necessary


# Logical operations

@dataclass
class LogicalOrNode(BinaryLogicNode):
    """An AST node representing a logical or operation."""

    op_name: str = '||'

    # add your code below if necessary


@dataclass
class LogicalAndNode(BinaryLogicNode):
    """An AST node representing a logical and operation."""

    op_name: str = '&&'

    # add your code below if necessary


# Arithmetic comparisons

@dataclass
class LessNode(BinaryCompNode):
    """An AST node representing a less than operation."""

    op_name: str = '<'

    # add your code below if necessary


@dataclass
class LessEqualNode(BinaryCompNode):
    """An AST node representing a less than or equal operation.

    lhs is the left-hand operand and rhs is the right-hand operand.
    """

    op_name: str = '<='

    # add your code below if necessary


@dataclass
class GreaterNode(BinaryCompNode):
    """An AST node representing a greater than operation."""

    op_name: str = '>'

    # add your code below if necessary


@dataclass
class GreaterEqualNode(BinaryCompNode):
    """An AST node representing a greater than or equal operation."""

    op_name: str = '>='

    # add your code below if necessary


# Equality comparisons

@dataclass
class EqualNode(EqualityTestNode):
    """An AST node representing an equality comparison."""

    op_name: str = '=='

    # add your code below if necessary


@dataclass
class NotEqualNode(EqualityTestNode):
    """An AST node representing an inequality comparison."""

    op_name: str = '!='

    # add your code below if necessary


# Other binary operations

@dataclass
class AssignNode(BinaryOpNode):
    """An AST node representing an assignment operation."""

    op_name: str = '='

    # add your code below
    def gen_function_defs(self, ctx):
        # breakpoint()
        return f'{self.lhs.gen_function_defs(ctx)} {self.op_name} {self.rhs.gen_function_defs(ctx)}'

@dataclass
class PushNode(BinaryOpNode):
    """An AST node representing an array insertion operation."""

    op_name: str = '<<'

    # add your code below


@dataclass
class PopNode(BinaryOpNode):
    """An AST node representing an array extraction operation."""

    op_name: str = '>>'

    # add your code below
