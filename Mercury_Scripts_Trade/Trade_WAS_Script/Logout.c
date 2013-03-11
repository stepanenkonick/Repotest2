/* Test Scripts for Stock Trader 1.0 Benchmark.

For use with Mercury Interactive's "LoadRunner version 7.51"

Use at own risk. May not work with other versions of Loadrunner.

Scripts modified to include comments, no other changes.

Verified by Jody Winningham, CN2 Technology. 

*/
#include "as_web.h"
#include "lrw_custom_body.h"

int status;

Logout()
{
		lr_think_time(1);
	lr_start_transaction("Logout");
status = web_url("Logoff",
		"URL=http://{Server}:{port}/trade/app?action=logout",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://{Server}:{port}/trade/app?action=sell&holdingID=7000",
		"Snapshot=t40.inf",
		"Mode=HTML",
		LAST);
if (status == LR_FAIL)
{
     lr_error_message("Error: %s", "Logout Failed - Aborted VU");
     lr_abort();
}
lr_end_transaction("Logout", LR_AUTO);
return 0;
}
