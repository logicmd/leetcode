// 一定要先想出正确的方法，暴力也无所谓，再优化
public class BestTimetoBuyandSellStockIII {
    public int maxProfit(int[] prices) {
        // Start typing your Java solution below
        // DO NOT write main() function
        if (prices.length == 0) {
            return 0;
        }

        int n = prices.length;

        int[] savedMin = {Integer.MAX_VALUE, Integer.MAX_VALUE};
        int[] savedSaleTime = {-1, -1};
        int[] savedProfit = new int[2];
        int total = 0;
        int savedBuyTime = 0;

        for (int mid=0; mid<n; mid++) {
            int profitCandidate = 0;
            int saleTime = savedSaleTime[0];
            int min = savedMin[0];
            int profit = -1;

            for (int i=saleTime+1; i<=mid; i++) {
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

            int buyTime = savedBuyTime >= mid ? savedBuyTime : mid;
            profitCandidate = 0;
            saleTime = mid - 1;
            min = Integer.MAX_VALUE;
            profit = -1;

            for (int i=buyTime; i<n; i++) {
                if (min > prices[i]) {
                    min = prices[i];
                    buyTime = i;
                }
                profitCandidate = prices[i] - min;
                if (profitCandidate > profit) {
                    profit = profitCandidate;
                    saleTime = i;
                    savedBuyTime = buyTime;
                }
            }

            savedSaleTime[1] = saleTime;
            savedMin[1] = min;
            savedProfit[1] = profit;

            if(total < savedProfit[0] + savedProfit[1]) {
                total = savedProfit[0] + savedProfit[1];
            }

        }
        //System.out.println(savedMin[0] + " " + savedSaleTime[0] +
        //    " " + savedMin[1] + " " + savedSaleTime[1]);
        return total;
    }

    public static void main(String[] args) {
        BestTimetoBuyandSellStockIII b = new BestTimetoBuyandSellStockIII();
        int[] prices = {1,2};
        System.out.println(b.maxProfit(prices));
    }

}