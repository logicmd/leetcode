public class BestTimetoBuyandSellStockII {
    public int maxProfit(int[] prices) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if (prices.length <= 1) {
            return 0;
        }


        int profit = 0;
        for (int i=1; i<prices.length; ++i) {
            int minus = prices[i] - prices[i-1];
            if ( minus > 0 ) {
                profit += minus;
            }

        }
        return profit;
    }
}