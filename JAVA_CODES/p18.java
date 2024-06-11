import java.awt.*;    
import java.awt.event.*; 

public class p18 extends Frame{
    	public p18() {
       	Button button = new Button("Click Me");
        	setLayout(null);
        	button.setBounds(100, 80, 100, 30);
        	add(button);
        	setSize(300, 200);

        	addWindowListener(new WindowAdapter() {
           	 public void windowClosing(WindowEvent e) {
              dispose();
            	   }
        	});
        	setLocationRelativeTo(null);
        	setVisible(true);
   	}
    	public static void main(String[] args) {
       	 new p18();
    	}
}
