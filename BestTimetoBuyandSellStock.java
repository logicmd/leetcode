public class BestTimetoBuyandSellStock {
    public int maxProfit(int[] prices) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if (prices.length == 0) {
            return 0;
        }
        int minus = 0;
        int min = Integer.MAX_VALUE;
        int profit = 0;
        for (int i=0; i<prices.length; ++i) {
            if (prices[i] < min) {
                min = prices[i];
            }
            profit = prices[i] - min;
            if (minus < profit) {
                minus = profit;
            }
        }
        return minus;
    }
}