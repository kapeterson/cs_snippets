import java.io.BufferedReader;
import java.io.FileReader;

public class JavaFileReader {

	public static void main(String[] args){

		System.out.println("OK");
		try {
		BufferedReader br = new BufferedReader(new FileReader("test.txt"));
		String line;
		while ( br.ready()) {
			line = br.readLine();
			System.out.println(line);
		}

		br.close();
		} catch (Exception e ) {
			System.out.println("Error " + e.getMessage());
		}
	}

}
