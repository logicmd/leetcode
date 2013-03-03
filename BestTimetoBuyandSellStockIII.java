// 一定要先想出正确的方法，暴力也无所谓，再优化
// AC
public class BestTimetoBuyandSellStockIII {
    public int maxProfit(int[] prices) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if (prices.length == 0) {
            return 0;
        }

        int n = prices.length;
        int profit[] = new int[n];
        int profitCandidate = 0;
        int min = Integer.MAX_VALUE;

        for (int i = 0; i < n; ++i) {
            if (prices[i] < min) {
                min = prices[i];
            }
            profitCandidate = prices[i] - min;
            if (i>0) {
                profit[i] = profit[i-1];
            }
            if (profit[i] < profitCandidate) {
                profit[i] = profitCandidate;
            }
        }

        int max = Integer.MIN_VALUE;
        int total = 0;
        int profit_2nd = 0;
        for (int i = n-1; i >= 0; --i) {
            if (prices[i] > max) {
                max = prices[i];
            }
            profitCandidate = max - prices[i];
            if (profit_2nd < profitCandidate) {
                profit_2nd = profitCandidate;
            }
            if (total < profit_2nd + profit[i]) {
                total = profit_2nd + profit[i];
            }
        }

        return total;
    }

    public static void main(String[] args) {
        BestTimetoBuyandSellStockIII b = new BestTimetoBuyandSellStockIII();
        int[] prices = {1,2};
        System.out.println(b.maxProfit(prices));
    }

}