public class BestTimetoBuyandSellStockIII {
    public int maxProfit(int[] prices) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if (prices.length == 0) {
            return 0;
        }
        int[] minus = new int[2];
        int m = 0;
        int min = Integer.MAX_VALUE;
        int profit = 0;
        for (int i=0; i<prices.length-1; ++i) {
            if (prices[i] < min) {
                min = prices[i];
            }
            profit = prices[i] - min;
            if (m < profit) {
                m = profit;
            }
            if (prices[i+1] < min) {
                updateMinus(minus, m);
            }

        }
        return minus[0]+minus[1];
    }

    void updateMinus(int[] minus, int profit) {
        if (profit > minus[0]) {
            if (profit > minus[1]) {
                minus[0] = minus[1];
                minus[1] = profit;
            } else {
                minus[0] = profit;
            }
        }
    }
}