<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language ?>" lang="<?php print $language ?>">
<head>
    <title><?php print $head_title ?></title>
    <?php print $head ?>
    <?php print $styles ?>
    <?php print $scripts ?>
</head>
<body>
	<div id="header">
		<div id="logo">		
			<a href="<?php print check_url($base_path); ?>"><?php
			if ($logo) {
			print '<img src="'. check_url($logo) .'" />';
			}
			?></a>			
		</div>		
		<div id="primary">
			<?php if (is_array($primary_links)) : ?>
			<?php 
			foreach($primary_links AS $links){
				echo l($links['title'], $links['href']);
	          }
			endif;
			?>
		</div>		
		<div id="intro">			
			<h2><a href="<?php print check_url($base_path); ?>"><?php print check_plain($site_name); ?></a></h2>
			<p><?php print check_plain($site_slogan); ?></p>
		</div>
	</div>
	<div id="base">		
		<div id="menuleft">
			<?php if ($sidebar_left != ""): ?>
			<?php print $sidebar_left ?>
			<?php endif; ?>  
			<?php if ($sidebar_right != ""): ?>
			<?php print $sidebar_right ?>
			<?php endif; ?>			
		</div>				
		<div id="right">		
			<?php if ($breadcrumb): print $breadcrumb; endif; ?>
			<?php print $header; ?>
			
			<?php if ($title != ""): ?>
			<h1><?php print $title ?></h1>
			<?php endif; ?>			
			<?php if ($tabs != ""): ?>
			<?php print $tabs ?>
			<?php endif; ?>			
			<?php if ($mission != ""): ?>
			<div class="mission"><?php print $mission ?></div>
			<?php endif; ?>
			<?php if ($help != ""): ?>
			<p id="help"><?php print $help ?></p>
			<?php endif; ?>
			<?php if ($messages != ""): ?>
			<div id="message"><?php print $messages ?></div>
			<?php endif; ?>
			<?php print($content) ?>			
		</div>
		<div style="clear: both"></div>	
		<div id="footer">
			<p><?php print $footer_message ?></p>
		</div>
	</div>
	<div class="copy">
		<p>powered by <a href="http://www.drupal.org/">Drupal</a> - <!-- Please do not remove this command line --> template <a href="http://www.metp.ru/">metp</a></p>
	</div>
</body>
</html>