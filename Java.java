/**
 * Give the package path
 * Use import to import the required packges 
 */

Class Java {
	
	//member variables and member functions
	int javaPrimitiveInt;
	Integer javaObjectInt;
	
	//Declare /Define member functions
	private void matrixEnter() {
		System.out.println("Please enter into the abstract world of matrix");
		System.out.println("Where you never care about *.h files");
	}
	
	public static void main (String args[]) {
		//Object is created on heap
		Java java = new Java();
	}
}