<?php

/**
 * Implements hook_drush_help().
 */
function drush_demo_drush_help($command) {
  switch ($command) {
    case 'drush:my-command':
      return dt('Run my command');
  }
}

/**
 * Implements hook_drush_command().
 */
function drush_demo_drush_command() {
  $items = array();
  $items['my-command'] = array(
    // The dt() function is used to provide string translations.
    // This is used in replacement of the Drupal t() function for Drush commands.
    'description' => dt('Run my command.'),
    // An array of arguments can be used to accept user input from the command line.
    'arguments'   => array(
      'arg1'    => dt('An optional example argument'),
    ),
    // An array of examples can be added to provide additional help to the user.
    'examples' => array(
      'Standard example' => 'drush my-command',
      'Argument example' => 'drush my-command 5',
    ),
    // Aliases are nice ways to shorten the Drush command. 
    'aliases' => array('myc'),
  );
  return $items;
}

/**
 * Callback function for drush my-command. 
 * Callback is called by using drush_hook_command() where
 * hook is the name of the module (MYMODULE) and command is the name of
 * the Drush command with all "-" characters converted to "_" characters (my_command)
 *
 * @param $arg1 - An optional argument
 */
function drush_drush_demo_my_command($arg1 = NULL) {
  // check if the argument was passed in and just print it out
  if (isset($arg1)) {
   drush_print($arg1);
  }
  // log to the command line with an OK status
  drush_log('Running my-command', 'ok');
}

/**
 * Useful commands
 */
// drush_log('Log an event using drush', 'warning');
// drush_set_error('Set an error with drush.');
// dt('Translate strings with drush');
// drush_print('Print to command line with drush');
// drush_print_table($rows, TRUE); //print a command line table with drush
// drush_confirm('Are you sure you want to continue?', $indent = 0); //Add drush confirmation