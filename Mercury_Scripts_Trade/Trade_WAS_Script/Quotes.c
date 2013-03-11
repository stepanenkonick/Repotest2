/* Test Scripts for Stock Trader 1.0 Benchmark.

For use with Mercury Interactive's "LoadRunner version 7.51"

Use at own risk. May not work with other versions of Loadrunner.

Scripts modified to include comments, no other changes.

Verified by Jody Winningham, CN2 Technology. 

*/
#include "as_web.h"
#include "lrw_custom_body.h"
int status;
Quotes()
{
	
lr_think_time(1);
	lr_start_transaction("Quotes");

	status = web_url("Quotes/Trade",
		"URL=http://{Server}:{port}/trade/app?action=quotes&symbols=s:{Symbol},s:{Symbol},s:{Symbol},s:{Symbol}",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://{Server}:{port}/trade/app",
		"Snapshot=t35.inf",
		"Mode=HTML",
		LAST);
if (status == LR_FAIL)
{
     lr_error_message("Error: %s", "Quotes Failed - Aborted VU");
     lr_abort();
}

	
lr_end_transaction("Quotes", LR_AUTO);
	

	

	

	return 0;
}
