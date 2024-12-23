public class Main {
    public class Stack{
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

    public class EmptyStackException extends RuntimeException {
        public EmptyStackException() {
            super();
        }
        public EmptyStackException(String msg) {
            super(msg) ;
        }
    }

    public class FullStackException extends RuntimeException {
        public FullStackException() {
            super();
        }
        public FullStackException(String msg) {
            super(msg);
        }
    }

    static boolean isOperator (char c) { 
        return (c == '+' || c == '-' || c == '*' || c == '/' || c=='(' || c== ')' ) ;
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
        if (Cin=='*' && stTop== null) result=true ;
        if (Cin=='/' && stTop== null) result=true ;
        return result;
    }
    static String inToPost(String Sinput) {
        int j = Sinput.length() ;
        Stack stk ;
        char[] post ;
        post = new char[j] ;
        for(int i=0; i<Sinput.length(); i++) {
            char in = Sinput.charAt(i) ;
            if (Character.isDigit(in)) post[j-1] = in ; 
            if(isOperator(in)) {

            }

        }

        
        return "";
    }
    static String inToPre(String Sinput) {
        return "" ;
    }
    public static void main(String args[]){
        String sin ;
        sin = "b+a*c/d" ;
        System.out.println(inToPost(sin));
        System.out.println(inToPre(sin));
    }
}
