import org.junit.Test;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;

public class TestBank {

    @Test
    public void TestGetTotalMethod(){
        Account account = new Account();

        assertEquals(12,account.getTotal());
    }

    @Test
    public void TestAddMoneyMethod(){
       Account account =  new Account();
       account.AddMoney(10);
       assertEquals(10 , account.getTotal());
    }
}
