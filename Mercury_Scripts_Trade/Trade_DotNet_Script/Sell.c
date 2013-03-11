///Script not used in benchmark

Sell()
{
	
	
	lr_think_time(1);
	lr_start_transaction("Sell");
	

web_set_max_html_param_len("4690");

	 web_reg_save_param("WCSParam1",
		"LB/IC=Order.aspx?action=sell&quantity=100&holdingID=",
		"RB/IC=\">sell",
		"Ord=1",
		"Search=body",
		LAST);

 

	web_url("Portfolio2",
		"URL=http://{Server}/TRADE/portfolio.aspx",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://{Server}/TRADE/Order.aspx",
		"Snapshot=t82.inf",
		"Mode=HTTP",
		LAST);


	web_url("sell",
		"URL=http://{Server}:{port}/TRADE/Order.aspx?action=sell&quantity=100.00&holdingID={WCSParam1}&symbol=s:98",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://192.168.4.142/TRADE/app?action=portfolio",
		"Snapshot=t83.inf",
		"Mode=HTTP",
		LAST);

lr_end_transaction("Sell", LR_AUTO);

return 0;
}
