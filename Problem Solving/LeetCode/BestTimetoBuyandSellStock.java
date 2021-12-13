package problemSolving;


public class BestTimetoBuyandSellStock {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		// int[] prices = {7,1,5,3,6,4};
		int[] prices = {2,1,2,1,0,1,2};

		System.out.println(maxProfit(prices));
	}
	
    public static int maxProfit(int[] prices) {
        // ����ΰԻ缭 �� ���Ŀ� ���� ��ΰ��ȱ�
    	
    	int buy = -1;
    	int sell = -1;
    	int profit = -1;
    	
    	for(int price : prices) {
    		if(buy ==-1) {
    			buy = price;
    		}
    		else {
    			// ������ ������ �������� ũ�ٸ� �Ǹ�
    			int newprofit = price - buy;
    			if(newprofit > profit) {
    				profit = price - buy;
    				sell = price;
    				//System.out.println("SELL1:"+sell);
    			}
    			
    			// ���ñ��Ű��� ���� ���Ű����� �δٸ� ����
    			if(price < buy) {
    				buy = price;
    				//System.out.println("buy:"+buy);
    			}
    			// �����Ѱ� �ְ�, ���� �ǸŰ��� ���� �ǸŰ����� ��δٸ� �Ǹ�
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
