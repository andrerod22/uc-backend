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
    # def gen_function_defs(self, ctx):
        # Check later (ASK Piazza)
        # breakpoint()
        # self.expr
        # ctx.print(';', indent=False)
        # super().gen_function_defs(ctx)


@dataclass
class BlockNode(ASTNode):
    """An AST node representing a block of statements.

    statements is a list of statement nodes.
    """

    statements: List[StatementNode]

    # add your code below if necessary
    def gen_function_defs(self, ctx):
        """Generate function definitions for the statements in this block."""
        for statement in self.statements:
            statement.gen_function_defs(ctx)



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
    # if (test) { then_block } else { else_block }
    # Note: else block is optional --> check if else_block is None
    def gen_function_defs(self, ctx):
        ctx.indent = '\t'
        ctx.print(f'if ({self.test.gen_function_defs(ctx)}) ', indent=True)
        ctx.print('{', indent=True)
        if self.then_block.gen_function_defs(ctx):
            ctx.print(f'{self.then_block.gen_function_defs(ctx)}', indent=True)
        ctx.print('}', indent=True)

        if self.else_block:
            ctx.print(f'else ', indent=True)
            ctx.print('{', indent=True)
            if self.else_block.gen_function_defs(ctx):
                ctx.print(f'{self.else_block.gen_function_defs(ctx)}', indent=True)
            ctx.print('}', indent=True)
        # Check later (ASK Piazza)
        # super().gen_function_defs(ctx)


@dataclass
class WhileNode(StatementNode):
    """An AST node representing a while statement.

    test is the condition and body is a block representing the body.
    """

    test: ExpressionNode
    body: BlockNode

    # add your code below
    # while (test) { body }
    def gen_function_defs(self, ctx):
        ctx.indent = '\t'
        ctx.print(f'while ({self.test.gen_function_defs(ctx)}) ', indent=True)
        ctx.print('{', indent=True)
        if self.body.gen_function_defs(ctx):
            ctx.print(f'{self.body.gen_function_defs(ctx)}', indent=True)
        ctx.print('}', indent=True)
        # Check later (ASK Piazza)
        # super().gen_function_defs(ctx)


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
    # for (init; test; update) { body }
    # Note: init, test, and update are optional --> check if they are None
    def gen_function_defs(self, ctx):
        ctx.indent = '\t'
        ctx.print('for (', indent=True)
        if self.init:
            ctx.print(f'{self.init.gen_function_defs(ctx)}', indent=True)
        ctx.print('; ')
        if self.test:
            ctx.print(f'{self.test.gen_function_defs(ctx)}', indent=True)
        ctx.print('; ')
        if self.update:
            ctx.print(f'{self.update.gen_function_defs(ctx)}', indent=True)
        ctx.print(') ', indent=True)
        ctx.print('{', indent=True)
        if self.body.gen_function_defs(ctx):
            ctx.print(f'{self.body.gen_function_defs(ctx)}', indent=True)
        ctx.print('}', indent=True)
        # Check later (ASK Piazza)
        # super().gen_function_defs(ctx)


@dataclass
class BreakNode(StatementNode):
    """An AST node representing a break statement."""

    # add your code below
    def gen_function_defs(self, ctx):
        ctx.indent = '\t'
        ctx.print('break;', indent=True)

@dataclass
class ContinueNode(StatementNode):
    """An AST node representing a continue statement."""

    # add your code below
    def gen_function_defs(self, ctx):
        ctx.indent = '\t'
        ctx.print('continue;', indent=True)


@dataclass
class ReturnNode(StatementNode):
    """An AST node representing a return statement.

    expr is the return expression if there is one, None otherwise.
    """

    expr: Optional[ExpressionNode]

    # add your code below
    def gen_function_defs(self, ctx):
        ctx.indent = '\t'
        if self.expr:
            ctx.print(f'return {self.expr.gen_function_defs(ctx)};', indent=True)
        else:
            ctx.print('return;', indent=True)


@dataclass
class ExpressionStatementNode(StatementNode):
    """An AST node representing a statement of just an expression.

    expr is the expression.
    """

    expr: ExpressionNode

    # add your code below if necessary
    def gen_function_defs(self, ctx):
        ctx.indent = '\t'
        if self.expr:
            # breakpoint()
            ctx.print(self.expr.gen_function_defs(ctx), indent=True, end='')
            ctx.print(';', indent=False)
