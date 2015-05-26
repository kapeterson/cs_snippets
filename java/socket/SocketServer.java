import java.io.IOException;


import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;


public class SocketServer {

	public static void main ( String[] args ) throws IOException {

		ServerSocket listender = new ServerSocket(9090);
		System.out.println("OK brah");

		while ( true ) {
			
			Socket socket = listener.accept();
		}	
	}
}
