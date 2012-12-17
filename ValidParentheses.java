// One time AC...
import java.util.Stack;

public class ValidParentheses {

    public static void main(String args[]){
        ValidParentheses vp = new ValidParentheses();
        System.out.println(
            vp.isValid("[")
            );
    }
    public boolean isValid(String s) {
        // Start typing your Java solution below
        // DO NOT write main() function
        Stack<Character> stack = new Stack<Character>();
        for (char c:s.toCharArray()) {
            if ( !stack.empty() && c == getPair(stack.peek()) ) {
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        return stack.empty();
    }

    public char getPair(char c) {
        switch(c) {
            case '{':
                return '}';
            case '(':
                return ')';
            case '[':
                return ']';
            default:
                return ' ';
        }
    }

}