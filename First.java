
import java.awt.*;
class First extends Frame{
    First(){
        Button b =new Button("click me");
        b.setBounds(30,100,80,30);

        add(b);
        setSize(300,300);
        FlowLayout l=new FlowLayout();
        setLayout(l);
        // Button b=new Button();
        // btnColor.setLabel("green");
        // setVisible(true);
    }
    public static void main(String args[]){
        First f=new First();
    }
}