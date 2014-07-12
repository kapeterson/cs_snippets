
public class SimpleClass {

    int value = 0;
    public SimpleClass(){

    }

        
    public SimpleClass(int v ) {

	value = v;
   }
  
    public int getValue(){
	return value;
   }

	public void setValue(int v){
		value = v;
	}
     public static void main(String args[]){
  	System.out.println("OK\n");
	SimpleClass tClass = new SimpleClass();
        SimpleClass tClass2 = new SimpleClass(1);
        System.out.println("Value of value is " + tClass.getValue());


	System.out.println("Value of v2 is " + tClass2.getValue());
	tClass.setValue(99);
 	System.out.println("Updated value v1 is " + tClass.getValue());
    }

}
