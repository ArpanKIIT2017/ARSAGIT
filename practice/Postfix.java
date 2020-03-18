/*
 *
 * Evaluate a POSTFIX expr
 * Infix: 2 + 3
 * Postfix: 23+
 *
 *
 * Infix: 2 + 4 * 3
 * Postfix: 243*+
 *
 * User will enter a postfix notation
 * You have to evaluate using a stack and display the resuly
 *
 *
 * Example: 243*+
 * 
 * Step 1: 2 is a number so push on top of stack ----- stack = [2, ]
 * Step 2: 4 is a number so push on top of stack ----- stack = [2, 4, ]
 * Step 3: 3 is a number so push on top of stack ----- stack = [2, 4, 3, ]
 * Step 4: * is an operator so pop two operands and calculate op1 * op* and push back the result ----- stack = [2, 12, ]
 * Step 5: + is an operator so similar to step 4 ----- stack = [16, ]
 *
 * Step 6: pop() the result from the stack and display
 *
*/



import java.util.*;

class Postfix {
	
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter expression in reverse polish: ");
		String expr = sc.nextLine();

		Stack<Integer> stack = new Stack<>();
		
		try {

			for (int i = 0; i < expr.length(); i++) {
				char ch = expr.charAt(i);
				
				if (Character.isDigit(ch)) {	
					// To parse char as a number
					int num = Integer.parseInt(ch+"");
					//TODO: Push this number onto stack
					stack.push(num);

				} else {
					// POP two operands from stack
					int op1 = stack.pop();
					int op2 = stack.pop();
					
					// Check which operator is in ch
					// Operate and push the result back on stack
					switch (ch) {
						case '+' : 
							stack.push(op1 + op2);
							break;
						case '-' : 
							//TODO
							stack.push(op1 - op2);
							break;
						case '*' : 
							//TODO: Implement
							stack.push(op1 * op2)
							break;
						case '/' : 
							//TODO: Implement
							stack.push(op1 / op2)
							break;
					
					}

				}
			}
			
			// Pop the last element on top of stack, that is the evaluated result
			System.out.println(stack.pop());

		} catch (Exception ex) {
			System.out.println("Invalid Expression....");
		}
	}
}

