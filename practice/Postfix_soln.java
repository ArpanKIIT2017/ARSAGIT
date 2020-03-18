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
					stack.push(Integer.parseInt(ch+""));
				} else {
					switch (ch) {
						case '+': stack.push(stack.pop() + stack.pop()); break;
						case '-': stack.push(stack.pop() - stack.pop()); break;
						case '*': stack.push(stack.pop() * stack.pop()); break;
						case '/': stack.push(stack.pop() / stack.pop()); break;
					}
				}
			}

			System.out.println(stack.pop());

		} catch (Exception ex) {
			System.out.println("Invalid Expression....");
		}
	}
}

