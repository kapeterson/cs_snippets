import java.io.DataInputStream;
import java.io.IOException;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;

public class MySocketServer {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		ServerSocket listener = new ServerSocket(9090);
		
		while (true){
			Socket socket = listener.accept();
			DataInputStream in = new DataInputStream(socket.getInputStream());
			int read = 0;
			byte[] buffer = new byte[1024];
			while ((read = in.read(buffer) ) != -1){
				String output = new String(buffer, 0, read);
				System.out.print(output);
				System.out.flush();
			}
			
			//System.out.println("We gone\n");
			//PrintStream out = new PrintStream(socket.getOutputStream(),true);
			//out.print("ACK");
			//out.flush();
		}
		
	}

}
