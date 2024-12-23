import java.util.EmptyStackException;

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

    static String inToPost(String Sinput) {
        
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
