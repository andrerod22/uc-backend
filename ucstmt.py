"""
ucstmt.py.

This file contains definitions of AST nodes that represent uC
statements.

Project UID c49e54971d13f14fbc634d7a0fe4b38d421279e7
"""

from dataclasses import dataclass
from typing import List, Optional
from ucbase import ASTNode
from ucerror import error
from ucexpr import ExpressionNode
import uctypes


@dataclass
class StatementNode(ASTNode):
    """The base class for all statement nodes."""

    # add your code below if necessary


@dataclass
class BlockNode(ASTNode):
    """An AST node representing a block of statements.

    statements is a list of statement nodes.
    """

    statements: List[StatementNode]

    # add your code below if necessary


@dataclass
class IfNode(StatementNode):
    """An AST node representing an if statement.

    test is the condition, then_block is a block representing the then
    case, and else_block is a block representing the else case.
    """

    test: ExpressionNode
    then_block: BlockNode
    else_block: BlockNode

    # add your code below


@dataclass
class WhileNode(StatementNode):
    """An AST node representing a while statement.

    test is the condition and body is a block representing the body.
    """

    test: ExpressionNode
    body: BlockNode

    # add your code below


@dataclass
class ForNode(StatementNode):
    """An AST node representing a for statement.

    init is the initialization, test is the condition, update is the
    update expression, and body is a block representing the body.
    init, test, and update may be None if the corresponding expression
    is omitted.
    """

    init: Optional[ExpressionNode]
    test: Optional[ExpressionNode]
    update: Optional[ExpressionNode]
    body: BlockNode

    # add your code below


@dataclass
class BreakNode(StatementNode):
    """An AST node representing a break statement."""

    # add your code below


@dataclass
class ContinueNode(StatementNode):
    """An AST node representing a continue statement."""

    # add your code below


@dataclass
class ReturnNode(StatementNode):
    """An AST node representing a return statement.

    expr is the return expression if there is one, None otherwise.
    """

    expr: Optional[ExpressionNode]

    # add your code below


@dataclass
class ExpressionStatementNode(StatementNode):
    """An AST node representing a statement of just an expression.

    expr is the expression.
    """

    expr: ExpressionNode

    # add your code below if necessary
