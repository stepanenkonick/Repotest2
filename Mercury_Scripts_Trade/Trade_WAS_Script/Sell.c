

///Script not used in benchmark

Sell()
{
	lr_think_time(1);
	lr_start_transaction("Sell");

web_set_max_html_param_len("4690");

	web_reg_save_param("WCSParam1",
		"LB/IC=<A href=\"app?action=sell&holdingID=",
		"RB/IC=\"",
		"Ord=1",
		"Search=body",
		"RelFrameId=1",
		LAST);

web_url("Portfolio",
		"URL=http://{Server}:{port}/trade/app?action=portfolio",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://192.168.4.123/trade/app?action=account",
		"Snapshot=t38.inf",
		"Mode=HTML",
		LAST);

	web_url("sell",
		"URL=http://{Server}:{port}/trade/app?action=sell&holdingID={WCSParam1}",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://192.168.4.142/trade/app?action=portfolio",
		"Snapshot=t77.inf",
		"Mode=HTTP",
		LAST);

lr_end_transaction("Sell", LR_AUTO);

return 0;
}

