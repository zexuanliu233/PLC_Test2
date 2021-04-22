void error(void){
	return -1;
}

void statement(void){
	
}

/* whilestmt
 <whilestmt> -> 'while' '(' <boolexpr> ')' '{'<statement>'}' 
*/
 void whilestmt(void){
 	if(nextToken != WHILE_CODE)
 		error();
 	else{
 		lex();
 		if(nextToken != LEFT_PAREN)
			error();
		else{
			lex();
			boolexpr();
			if(nextToken != RIGHT_PAREN)
				error();
			else{
				lex();
				if(nextToken != LEFT_CURLY)
 					error();
 				else{
		 			lex();
		 			statement();
					if(nextToken != RIGHT_CURLY)
						error();
					else{
		 				lex();
					}
				}
			}
		}
	}
 }
 
 /* ifstmt
 <ifstmt> -> 'if' '(' <boolexpr> ')'<statement>['else' <statement>]
*/
void ifstmt(void) {
 if (nextToken != IF_CODE)
 	error();
 else {
	lex();
 	if (nextToken != LEFT_PAREN)
 		error();
 	else{
 		lex();
 		boolexpr();
 		if (nextToken != RIGHT_PAREN)
 			error();
 		else {
 			lex();
 			statement();
			if (nextToken == ELSE_CODE) {
		 		lex();
		 		statement();
				}
			}
		}
	}
}


