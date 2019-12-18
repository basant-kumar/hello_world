public class Account {

    private double totalBalance =  0.0;

    public void AddMoney(double amount) {
        totalBalance = totalBalance + amount;
    }

    public double getTotal() {
        return totalBalance;
    }

    public boolean TransferMoney(double amount) {
        totalBalance = totalBalance - amount;
        return true;
    }
}
