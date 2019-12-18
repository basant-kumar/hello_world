import org.junit.Assert;
import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class TestBank {

    /*@Test
    public void TestGetTotalMethod(){
        Account account = new Account();

        assertEquals(12,account.getTotal());
    }*/

    @Test
    public void TestAddMoneyMethod(){
       Account account =  new Account();
       double num = 10;
       account.AddMoney(num);
       //System.out.println(account.getTotal());
       //System.out.println(num);
       assertEquals(10, account.getTotal(), 0);
    }



}
