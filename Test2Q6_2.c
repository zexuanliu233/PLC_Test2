/* expr
 <expr> -> <term> {(+ | -) <term>}
 */
void expr(void) {
	 printf("Enter <expr>\n");
	 term();
	/* As long as the next token is + or -, get
	 the next token and parse the next term */
	 while (nextToken == '+' || nextToken == '-') {
		 lex();
		 term();
	 }
	 printf("Exit <expr>\n");
}

/* term
 <term> -> <factor> {(* | /) <factor>}
 */
void term(void) {
	 printf("Enter <term>\n");
	 factor();
	/* As long as the next token is * or /, get the
	 next token and parse the next factor */
	 while (nextToken == '*' || nextToken == '//') {
		 lex();
		 factor();
	 }
	 printf("Exit <term>\n");
}

/* factor
 <factor> -> id | int_constant | ( <expr> )
 */
void factor(void) {
	 printf("Enter <factor>\n");
	/* Determine which RHS */
	 if (nextToken == IDENT || nextToken == INT_LIT)
		/* Get the next token */
		 lex();
		/* If the RHS is ( <expr> ), call lex to pass over the
		 left parenthesis, call expr, and check for the right
		 parenthesis */
	 else { if (nextToken == LEFT_PAREN) {
		 lex();
		 expr();
		 if (nextToken == RIGHT_PAREN)
		 	lex();
		 else
		 	error();
		 }
		/* It was not an id, an integer literal, or a left
		 parenthesis */
		 else
		 error();
	 }
	 printf("Exit <factor>\n");
}
