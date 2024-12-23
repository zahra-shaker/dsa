import java.util.Scanner;

public class Main {
    public static class EmptyStackException extends RuntimeException {
        public EmptyStackException() {
            super();
        }
        public EmptyStackException(String msg) {
            super(msg) ;
        }
    }

    public static class FullStackException extends RuntimeException {
        public FullStackException() {
            super();
        }
        public FullStackException(String msg) {
            super(msg);
        }
    }
    public static class Stack{
        public int size = 100 ;
        private int top = -1 ;
        private char elements[] ;
        public Stack(){
            elements = new char[size] ;
        }
        public Stack(int len) {
            size=len;
            elements = new char[size] ;
        }
        public char peek() {
            if(top==-1) throw new EmptyStackException() ;
            return elements[top] ;
        }
        public void push (char c) {
            if (top==size-1) throw new FullStackException();
            elements[++top] = c ; 
        }
        public char pop() {
            char c = peek() ;
            top-- ;
            return c;
        }
        public boolean isEmpty() {
            return top==-1;
        }
        public boolean isFull() {
            return top==size-1;
        }
    }

    static boolean isOperator (char c) { 
        return (c == '+' || c == '-' || c == '*' || c == '/' || c=='(' ) ;
    }

    static boolean Priority (char Cin, Character stTop) {
        boolean result = false ;
        if (Cin=='*' && stTop=='+') result=true ;
        if (Cin=='*' && stTop=='-') result=true ;
        if (Cin=='/' && stTop=='+') result=true ;
        if (Cin=='/' && stTop=='-') result=true ;
        if (Cin=='+' && stTop=='(') result=true ;
        if (Cin=='-' && stTop=='(') result=true ;
        if (Cin=='*' && stTop=='(') result=true ;
        if (Cin=='/' && stTop=='(') result=true ;
        if (Cin=='+' && stTop == null) result=true ;
        if (Cin=='-' && stTop == null) result=true ;
        if (Cin=='*' && stTop == null) result=true ;
        if (Cin=='/' && stTop == null) result=true ;
        return result;
    }
    static String inToPost(String Sinput) {
        int j = Sinput.length() ;
        Stack stk ;
        stk = new Stack(j) ;
        char[] post ;
        post = new char[j] ;
        j-- ;
        for(int i=0; i<j; i++) {
            char in = Sinput.charAt(i) ;
            if (Character.isDigit(in)) { 
                post[j] = in ;
                j-- ; }
            if (isOperator(in)) { 
                if (Priority(in,stk.peek())) {
                    stk.push(in);
                }
                if (in==')') {
                    while (stk.peek()!='(') {
                        post[j] = stk.pop() ;
                        j--;
                    }
                    stk.pop() ;
                }
                if (!Priority(in,stk.peek())) {
                    post[j] = stk.pop() ;
                    j-- ;
                }
            }
        }
        while (!stk.isEmpty()) {
            post[j] = stk.pop() ;
            j-- ; 
        }
        String result = new String(post) ;
        return result ;
    }
 
    static String inToPre(String Sinput) {
        int j = Sinput.length() ;
        Stack stOperand = new Stack(j) ;
        Stack stOperator = new Stack(j) ;
        for (int i=0 ; i<Sinput.length())

        return "" ;
    }
    public static void main(String args[]){
        String infix ;
        System.out.println("Enter infix form:");
        Scanner obj = new Scanner (System.in) ; 
        infix = obj.nextLine() ;
        System.out.println(inToPost(infix));
        System.out.println(inToPre(infix));
    }
}
