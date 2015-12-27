/*
 * DESCRIPTION      Unit tests for Valarade.
 * PROJECT          Valarade
 * AUTHOR           Chris Daley <chebizarro@gmail.com>
 *
 * Copyright (C) Chris Daley 2015
 */

using Gherkin;
using Gherkin.Pickles;

static void main (string[] args) {
	GLib.Test.init (ref args);
	
	GLib.TestSuite.get_root ().add_suite (new AstBuilderTest ().get_suite ());
	GLib.TestSuite.get_root ().add_suite (new GherkinDialectProviderTest ().get_suite ());
	GLib.TestSuite.get_root ().add_suite (new GherkinLineTest ().get_suite ());
	GLib.TestSuite.get_root ().add_suite (new ParserTest ().get_suite ());
	GLib.TestSuite.get_root ().add_suite (new CompilerTest ().get_suite ());
	
	GLib.Test.run ();

}
