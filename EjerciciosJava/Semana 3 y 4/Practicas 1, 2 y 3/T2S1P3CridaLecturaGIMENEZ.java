import java.io.*;


public class T2S1P3CridaLectura {
public static void main(String[] args) {
	
	Runtime r=Runtime.getRuntime();
	
	
	String comando= "java T2S1ExempleLectura"; 
	Process p;

	try{
		p=r.exec(comando);
		OutputStream os = p.getOutputStream();
 		os.write("Hola món\n".getBytes());
		os.flush();

		InputStream is = p.getInputStream();
		BufferedReader br = new BufferedReader(new InputStreamReader(is));
		
		String linia = "";
		while ((linia = br.readLine()) != null) {
 		
			System.out.println(linia);
        	}

		br.close();

		InputStream er = p.getErrorStream();
		BufferedReader brer = new BufferedReader(new InputStreamReader(er));
		String liner = null;
		while ((liner = brer.readLine()) != null) {
    			System.out.println("ERROR > " + liner);
		}

		brer.close();


		} catch(Exception e) {
			System.out.println ("Error en "+comando);
			e.printStackTrace();
			}
	}

}
