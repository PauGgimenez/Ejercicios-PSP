import java.io.*;

public class T2S1P2tasklistGuarda {
    public static void main(String[] args) {
        Runtime r = Runtime.getRuntime();
        String comando = "ps -ef";
        Process p = null;

        if (args.length < 1) {
            System.out.println("Se necesita nombre de fichero..");
            System.exit(1);
        }

	try {
		FileOutputStream fos = new FileOutputStream(args[0]);
		PrintWriter pw = new PrintWriter(fos);

		p = r.exec(comando);
		
		InputStream is = p.getInputStream();
		BufferedReader br = new BufferedReader(new InputStreamReader(is));
		
		String linia = "";
		while ((linia = br.readLine()) != null) {
 		
	                System.out.println("Inserisc en " + args[0] + " > " + linia);
        	        pw.println(linia);

                }
		
		br.close();
		pw.close();

	} catch (Exception e) {
		e.printStackTrace();

	}

	int exitVal;
	try {
		exitVal=p.waitFor();
		System.out.println("Valor d'eixida: " + exitVal);
	} catch (InterruptedException e) {
	e.printStackTrace();

	}

	
}	
}
