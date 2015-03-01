void StdScrMapController::DisplayCommand()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );

	line_ptr prompt = command_->GetPrompt();
	view_->ClearLine( 40, 0, 80 );
	view_->Put( 40, 0, prompt );
}
