public class T2S1Exemple2Unasalutacio {
	public static void main(String[] args){
	if (args.length<1){
		System.out.println ("Cal una salutació...");
		System.exit(1);
		}
	for (int i=0;i<5;i++){
		System.out.println(i+1 + "."+ args[0]);
		}
	}//fi main
} //T2S1Exemple2Unasalutacio
