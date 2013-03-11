/* Test Scripts for Stock Trader 1.0 Benchmark.

For use with Mercury Interactive's "LoadRunner version 7.51"

Use at own risk. May not work with other versions of Loadrunner.

Scripts modified to include comments, no other changes.

Verified by Jody Winningham, CN2 Technology. 

*/

#include "as_web.h"
#include "lrw_custom_body.h"

int status;

Account()
{
	
lr_think_time(1);
	lr_start_transaction("AccountSummary");
status = web_url("Account",
		"URL=http://{Server}/TRADE/account.aspx",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://{Server}/TRADE/TradeHome.aspx",
		"Snapshot=t80.inf",
		"Mode=HTTP",
		LAST);

if (status == LR_FAIL)
{
     lr_error_message("Error: %s", "Account Failed - Aborted VU");
     lr_abort();
}


lr_end_transaction("AccountSummary", LR_AUTO);
return 0;
}
