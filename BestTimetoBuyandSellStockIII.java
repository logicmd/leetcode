// 一定要先想出正确的方法，暴力也无所谓，再优化
public class BestTimetoBuyandSellStockIII {
    public int maxProfit(int[] prices) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if (prices.length == 0) {
            return 0;
        }

        int n = prices.length;

        int[] savedMin = new int[2];
        int[] savedSaleTime = new int[2];
        int[] savedProfit = new int[2];

        for (int mid=1; mid<n-1; mid++) {
            int profitCandidate = 0;
            int saleTime = savedSaleTime[0]；
            int min = savedMin[0];
            int profit = savedProfit[0];

            for (int i=saleTime + 1; i<=mid; i++) {
                if (min > prices[i]) {
                    min = prices[i];
                }
                profitCandidate = prices[i] - min;
                if (profitCandidate > profit) {
                    profit = profitCandidate;
                    saleTime = i;
                }
            }

            savedSaleTime[0] = saleTime;
            savedMin[0] = min;
            savedProfit[0] = profit;

            profitCandidate = 0;
            saleTime = savedSaleTime[1] < mid + 1 ? mid + 1 : savedSaleTime[1]；
            min = savedMin[1];
            profit = savedProfit[1];

            for (int i=saleTime + 1; i<n; i++) {
                if (min > prices[i]) {
                    min = prices[i];
                }
                profitCandidate = prices[i] - min;
                if (profitCandidate > profit) {
                    profit = profitCandidate;
                    saleTime = i;
                }
            }

        }
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