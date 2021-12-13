package problemSolving;


public class BestTimetoBuyandSellStock {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		// int[] prices = {7,1,5,3,6,4};
		int[] prices = {2,1,2,1,0,1,2};

		System.out.println(maxProfit(prices));
	}
	
    public static int maxProfit(int[] prices) {
        // 가장싸게사서 그 이후에 가장 비싸게팔기
    	
    	int buy = -1;
    	int sell = -1;
    	int profit = -1;
    	
    	for(int price : prices) {
    		if(buy ==-1) {
    			buy = price;
    		}
    		else {
    			// 이윤이 지난번 이윤보다 크다면 판매
    			int newprofit = price - buy;
    			if(newprofit > profit) {
    				profit = price - buy;
    				sell = price;
    				//System.out.println("SELL1:"+sell);
    			}
    			
    			// 오늘구매가가 지난 구매가보다 싸다면 구매
    			if(price < buy) {
    				buy = price;
    				//System.out.println("buy:"+buy);
    			}
    			// 구매한게 있고, 오늘 판매가가 지난 판매가보다 비싸다면 판매
    			if(buy >0 && price > sell) {
    				profit = price - buy;
    				sell = price;
    				//System.out.println("SELL:"+sell);
    			}
    		}
    	}
    	//System.out.println(buy+":"+sell);
    	if(profit < 0 ) profit = 0;
    	return profit;
        
    }

}
