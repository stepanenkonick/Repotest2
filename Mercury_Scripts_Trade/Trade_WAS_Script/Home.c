/* Test Scripts for Stock Trader 1.0 Benchmark.

For use with Mercury Interactive's "LoadRunner version 7.51"

Use at own risk. May not work with other versions of Loadrunner.

Scripts modified to include comments, no other changes.

Verified by Jody Winningham, CN2 Technology. 

*/

#include "as_web.h"
#include "lrw_custom_body.h"
int status;

Home()
{

lr_think_time(1);
	lr_start_transaction("Home");
	status = web_url("index.html",
		"URL=http://{Server}:{port}/trade/app?action=home",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=",
		"Snapshot=t1.inf",
		"Mode=HTML",
		LAST);
if (status == LR_FAIL)
{
     lr_error_message("Error: %s", "Home Failed - Aborted VU");
     lr_abort();
}
	

	lr_end_transaction("Home", LR_AUTO);

	return 0;
}
