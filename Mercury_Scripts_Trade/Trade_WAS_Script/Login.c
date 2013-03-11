/* Test Scripts for Stock Trader 1.0 Benchmark.

For use with Mercury Interactive's "LoadRunner version 7.51"

Use at own risk. May not work with other versions of Loadrunner.

Scripts modified to include comments, no other changes.

Verified by Jody Winningham, CN2 Technology. 

*/
#include "as_web.h"
#include "lrw_custom_body.h"

int status;

Login()
{
	
	lr_think_time(1);
	lr_start_transaction("LoginPage");

	status = web_url("app",
		"URL=http://{Server}:{port}/trade/app",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=",
		"Snapshot=t31.inf",
		"Mode=HTML",
		LAST);
if (status == LR_FAIL)
{
     lr_error_message("Error: %s", "Login Page Failed - Aborted VU");
     lr_abort();
}
	lr_end_transaction("LoginPage", LR_AUTO);

lr_think_time(1);
lr_start_transaction("Login");
	status = web_submit_data("app2",
		"Action=http://{Server}:{port}/trade/app",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://{Server}:{port}/trade",
		"Snapshot=t32.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=uid", "Value=uid:{UserID}", ENDITEM,
		"Name=passwd", "Value=xxx", ENDITEM,
		"Name=action", "Value=login", ENDITEM,
		LAST);

if (status == LR_FAIL)
{
     lr_error_message("Error: %s", "Login Failed - Aborted VU");
     lr_abort();
}
lr_end_transaction("Login", LR_AUTO);
	return 0;
}
