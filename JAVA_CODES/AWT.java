import java.awt.*; 
import java.awt.event.*; 
import java.applet.*; 

/* 
<applet code="CheckboxDemo" width=250 height=200> 
</applet> 
*/ 
public class AWT extends Applet implements ItemListener { 
    String msg = ""; // Message to be displayed
    Checkbox winXP, winVista, solaris, mac; // Declare checkboxes

    public void init() { 
        // Initialize checkboxes with labels and set initial state for winXP
        winXP = new Checkbox("Windows XP", null, true); 
        winVista = new Checkbox("Windows Vista"); 
        solaris = new Checkbox("Solaris"); 
        mac = new Checkbox("Mac OS"); 

        // Add checkboxes to the applet
        add(winXP); 
        add(winVista); 
        add(solaris); 
        add(mac); 

        // Register the applet as the item listener for each checkbox
        winXP.addItemListener(this); 
        winVista.addItemListener(this); 
        solaris.addItemListener(this); 
        mac.addItemListener(this); 
    } 

    
    // This method is called whenever an item event occurs
    public void itemStateChanged(ItemEvent ie) { 
        // Repaint the applet to update the displayed states of checkboxes
        repaint(); 
    } 

    // Display the current state of the checkboxes
    public void paint(Graphics g) { 
        msg = "Current state: "; 
        g.drawString(msg, 6, 80); 

        msg = " Windows XP: " + winXP.getState(); 
        g.drawString(msg, 6, 100); 

        msg = " Windows Vista: " + winVista.getState(); 
        g.drawString(msg, 6, 120); 

        msg = " Solaris: " + solaris.getState(); 
        g.drawString(msg, 6, 140); 

        msg = " Mac OS: " + mac.getState(); 
        g.drawString(msg, 6, 160); 
    } 
}

// import java.awt.*;
// import java.awt.event.*;
// public class AWT implements ActionListener{
//     private Label l;
//     private TextField tf;
//     private Button b;
//     private int count =0;
//     AWT(){
//         Frame f=new Frame();
//         FlowLayout fl=new FlowLayout();
//         f.setLayout(fl);

//         l=new Label("counter");
//         f.add(l);
//         tf= new TextField("0",10);
//         tf.setEditable(false);
//         f.add(tf);

//         b=new Button("click here");
//         f.add(b);
//         b.addActionListener(this);

//         f.setTitle("AWT PREP ");
//         f.setSize(300, 200);
//         f.setVisible(true);

//         f.addWindowListener(new WindowAdapter(){
//             public void windowClosing(WindowEvent e){
//                 f.dispose();
//             }
//         });
//     }
//     public static void main(String[] args) {
//         AWT obj=new AWT();
//     }
//     public void actionPerformed(ActionEvent evt){
//         ++count;
//         tf.setText(count+"");
//     }


// }
