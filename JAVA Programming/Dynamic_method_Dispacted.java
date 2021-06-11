class Phone
{
	
	Phone() 
	{
		System.out.println("The Phone is A Normal Phone");
	}
	

	void data()
	{
		System.out.print("The phone have not sopport Google Play store \n");
	}
	
	void normal()
	{
		System.out.println("The Smart Phone Have Very Low Price");
	}
}

class Smart_Phone extends Phone
{
	
	Smart_Phone() 
	{
		System.out.println("The Phone is A Smart Phone");
	}
	
	@Override
	
	void data()
	{
		System.out.print("The phone have sopport Google Play store \n");
	}
	
	void ismart()
	{
		System.out.println("The Smart Phone Have Very High Price");
	}
}

public class Dynamic_method_Dispacted {

	public static void main(String[] args) {
		
	Phone ph = new Smart_Phone();  		// This is a Object of Phone class
	
	ph.data();
	ph.normal();
	
	
	

	}

}
