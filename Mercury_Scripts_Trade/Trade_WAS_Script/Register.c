/* Test Scripts for Stock Trader 1.0 Benchmark.

For use with Mercury Interactive's "LoadRunner version 7.51"

Use at own risk. May not work with other versions of Loadrunner.

Scripts modified to include comments, no other changes.

Verified by Jody Winningham, CN2 Technology. 

*/
#include "as_web.h"
#include "lrw_custom_body.h"
int status;
Register()
{
	lr_think_time(1);
	lr_start_transaction("Register");
status = web_url("Register With Trade",
		"URL=http://{Server}:{port}/trade/register.jsp",
		"TargetFrame=",
		"Resource=0",
		"RecContentType=text/html",
		"Referer=http://{Server}:{port}/trade/app",
		"Snapshot=t43.inf",
		"Mode=HTML",
		LAST);
if (status == LR_FAIL)
{
     lr_error_message("Error: %s", "Register Failed - Aborted VU");
     lr_abort();
}
lr_end_transaction("Register", LR_AUTO);

	lr_think_time(1);
	lr_start_transaction("Register_Submit");
	status = web_submit_data("app",
		"Action=http://{Server}:{port}/trade/app",
		"Method=GET",
		"EncType=",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://{Server}:{port}/trade/register.jsp",
		"Snapshot=t44.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=Full Name", "Value=FirstName", ENDITEM,
		"Name=snail mail", "Value=314 145th Ave", ENDITEM,
		"Name=email", "Value=user@company.com", ENDITEM,
		"Name=user id", "Value=user{newuserid}", ENDITEM,
		"Name=passwd", "Value=xxx", ENDITEM,
		"Name=confirm passwd", "Value=xxx", ENDITEM,
		"Name=money", "Value=10000", ENDITEM,
		"Name=Credit Card Number", "Value=123-fake-ccnum-456", ENDITEM,
		"Name=action", "Value=register", ENDITEM,
		LAST);
if (status == LR_FAIL)
{
     lr_error_message("Error: %s", "Register Failed - Aborted VU");
     lr_abort();
}
lr_end_transaction("Register_Submit", LR_AUTO);
	return 0;
}
