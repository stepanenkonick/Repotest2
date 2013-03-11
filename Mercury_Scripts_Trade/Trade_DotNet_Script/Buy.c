/* Test Scripts for Stock Trader 1.0 Benchmark.

For use with Mercury Interactive's "LoadRunner version 7.51"

Use at own risk. May not work with other versions of Loadrunner.

Scripts modified to include comments, no other changes.

Verified by Jody Winningham, CN2 Technology. 

*/

#include "as_web.h"
#include "lrw_custom_body.h"
int status;
Buy()
{
	
lr_think_time(1);
	lr_start_transaction("Buy");
	
	status = web_submit_data("Order.aspx",
		"Action=http://{Server}/TRADE/Order.aspx",
		"Method=POST",
		"RecContentType=text/html",
		"Referer=http://{Server}/TRADE/quotes.aspx",
		"Snapshot=t85.inf",
		"Mode=HTTP",
		ITEMDATA,
		"Name=action", "Value=buy", ENDITEM,
		"Name=symbol", "Value=s:{Symbol}", ENDITEM,
		"Name=quantity", "Value=100", ENDITEM,
		LAST);
if (status == LR_FAIL)
{
     lr_error_message("Error: %s", "Buy Failed - Aborted VU");
     lr_abort();
}
		lr_end_transaction("Buy", LR_AUTO);


return 0;
}
