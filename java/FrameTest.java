import java.awt.Frame;
import java.awt.*;
import java.awt.event.*;

public class FrameTest extends Frame {
	private Button btn;
	private Label lblTest;
	private TextField tf;

	public FrameTest(){
		setLayout(new FlowLayout());
		lblTest = new Label("Weeee");
  		add(lblTest);
 		tf = new TextField("0",10);
		add(tf);	
		btn = new Button("PUSHME");
		add(btn);
		

		setTitle("WEEEEE");
		setSize(250,100);
		setVisible(true);

        }


  	public static void main(String[] args){
		FrameTest tt = new FrameTest();
	}
}
