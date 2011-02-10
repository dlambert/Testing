<?php
// $Id: gallery_help.inc,v 1.1.4.4 2007/03/30 11:25:11 kiz0987 Exp $

/**
 * gallery.module : gallery_help.inc
 * Help info
 */

/**
 * Implementation of hook_help
 */
function _gallery_help($section) {

  switch($section) {
		case 'filter#short-tip' :
			return gallery_filter_short_tip_translated();
		case 'filter#long-tip' :
			return gallery_filter_long_tip_translated();
    case 'admin/help#gallery':
      $output = t('
      <h3>Online Documentation</h3>
      <p>Complete documentation can be found on the <a href="http://drupal.galleryembedded.com">wiki</a>.</p>
      <h3>Settings</h3>
      <h4>Directory Settings</h4>
      <p>"URI of Gallery2" is the URI of the Gallery2 standalone location. Path from docroot to the directory main.php is located. Protocol / host name are both optional. Examples: /gallery2/, /sub/gallery2/, http://photos.example.com/,
      www.example.com/photos/main.php</p>
      <p>"Location of Gallery2" is the path of your gallery2 installation, either absolute (starts with "/") or relative to your Drupal installation directory. Normally this is auto-detected, but in case this fails you can turn off auto-detection and manually enter a value.</p> 
      <p>"Embed URI" is the URI needed to access Gallery2 through Drupal. This will end in \'?q=gallery\' (non-clean URLs) or \'gallery\' (clean URLs). Normally this is auto-detected, but in case this fails you can turn off auto-detection and manually enter a value.</p> 
      <p>Some examples:</p>
      <p>Example 1: If your directory structure and website structure is 
      <ul>
        <li>Drupal dir: /var/www/web/html/</li>
        <li>Gallery dir: /var/www/web/html/gallery2/</li> 
        <li>Website URL: http://www.example.com</li>
        <li>Standalone Gallery2 URL: http://www.example.com/gallery2/</li>
        <li>Then<ul>
          <li>"URI of Gallery2" = "/gallery2/" or "http://www.example.com/gallery2/"</li>
          <li>"Location of Gallery2" = "gallery2/" or "/var/www/web/html/gallery2/"</li>        
          <li>"Embed URI" = "?q=gallery" or "http://www.example.com/?q=gallery"</li>
          </ul>
      </ul>
      </p><p>Example 2: If your directory structure and website structure is 
      <ul>
        <li>Drupal dir: /var/www/web/html/drupal/</li>
        <li>Gallery dir: /var/www/web/html/gallery2/</li> 
        <li>Website URL: http://www.example.com/drupal</li>
        <li>Standalone Gallery2 URL: http://www.example.com/gallery2/</li>
        <li>Then<ul>
          <li>"URI of Gallery2" = "/gallery2/" or "http://www.example.com/gallery2/"</li>
          <li>"Location of Gallery2" = "../gallery2/" or "/var/www/web/html/gallery2/"</li>
          <li>"Embed URI" = "/drupal/?q=gallery" or "http://www.example.com/drupal/?q=gallery"</li>        
          </ul>
      </ul>
      </p><p>Example 3: If your directory structure and website structure is 
      <ul>
        <li>Drupal dir: /var/www/web/html/drupal/</li>
        <li>Gallery dir: /var/www/web/html/someotherdir/gallery2/</li> 
        <li>Website URL: http://www.example.com/</li>
        <li>Standalone Gallery2 URL: http://www.anotherexample.com/gallery2/</li>
        <li>Then<ul>
          <li>"URI of Gallery2" = "http://www.anotherexample.com/gallery2/"</li>
          <li>"Location of Gallery2" = "/var/www/web/html/someotherdir/gallery2/"</li>
          <li>"Embed URI" = "/drupal/?q=gallery" or "http://www.example.com/drupal/?q=gallery"</li>        
          </ul>
      </ul>
      </p>
      <h4>Full Name settings</h4>
      <p>Drupal does not have in-built support for full names but Gallery 2 does. If you would like full names in both then you can install profile.module in Drupal and define a "full name" field. Include the name of that field here. You can enable/disable this functionality at will, but it may leave some users with different full names in their Drupal and Gallery users, so it is not recommended.</p>
      <h4>Search settings</h4>
      <p>You can select how many items are returned per Gallery2 module. You can also specify whether thumbnails should be returned, and if so, how they should be formatted.</p>
      <h4>Error Logging settings</h4>
      <p>You can choose whether errors occuring in this module are logged in the watchdog, displayed in the browser, or both.</p>
      ');
      $output .= _gallery_g2image_help();
      return $output;
    case 'admin/settings/gallery':
      return t('');
    /* Used in the default value for the pages list in g2image settings */
    case 'admin/settings/gallery_g2image#pages':
      return "node/*\ncomment/*";
  }
}

function gallery_filter_short_tip_translated() {
	return t('You may link to Gallery2 items on this site <a href="@explanation-url">using a special syntax</a>.', array ('@explanation-url' => url('filter/tips', NULL, 'filter-gallery-0')));
}

function gallery_filter_long_tip_translated() {
	$prefix = variable_get("gallery_filter_prefix", "G2");

  return t('
	  <p><strong>Gallery2 Filter:</strong></p>

    <p>You can link to items in your embedded Gallery2 using a special code. This code will be replaced by a thumbnail image that is linked to the actual item in your Gallery. </p>

	  <p><em>Syntax:</em></p>

	  <blockquote><code>
	  ['. $prefix .':<em>item_id</em> n=<em>number</em> type=<em>type</em> size=<em>number</em> class=<em>name</em> frame=<em>name</em> album_frame=<em>name</em> item_frame=<em>name</em>]
	  </code></blockquote>

	  <ul><li>item_id (required): This is the item ID from Gallery2. If you look at the URL of the item, this is the last number. <em>Note that if the item_id is a single photo, n must be 1.</em></li>

	  <li>n (suggested): This is the number of photos you want the block to show. It will override whatever is set in the defaults (initially 1). Note: this will change past instances where you did not set n -- the reason for its suggested use.</li>

	  <li>type: The default type of gallery block. Any of the following may be used: <em>randomImage, recentImage, viewedImage, randomAlbum, recentAlbum, viewedAlbum, dailyImage, weeklyImage, monthlyImage, dailyAlbum, weeklyAlbum, monthlyAlbum, specificItem. </em> Note that for n=1, selectedItem is automatically chosen regardless of this parameter.</li>

	  <li>class: The block that Gallery2 returns is wrapped in a DIV so additional styling can be done. The classes for this DIV are located in g2_filter.css.  Included with the module are "left", "right", and "nowrap". These position the image block to the left or right or on a line all its own with the text not wrapping. You can also add your own class(es) to the CSS file and they will automatically be available.</li>

	  <li>size: The length of the longest side for the thumbnail. The other side is determined automatically to keep the same aspect ratio. This option (for Gallery2.2 and above) will use the gallery image that is closest in size, and so may end up using a smaller image and expanding it (lower quality). If so, use "exactsize". For Gallery2.1, if you want your size to be bigger than
the thumbnail size for that image as defined in your Gallery2, you must select "Full Size" in
the gallery settings page (but note that the full image will be returned and then resized by the
browser, so it may take a while to download).</li>

	  <li>exactsize: The length of the longest side for the thumbnail. The other side is determined automatically to keep the same aspect ratio. This option always ensures that the image is scaled
from a larger image and so image quality is maintained. This only works for Gallery2.2 and above.</li>

	  <li>frame/album_frame/item_frame: You can use just "frame" to assign a frame to the thumbnail regardless of whether it\'s for an album or a single item. Using aframe will only affect albums and iframe will only affect single items. Frames included with the default Gallery 2 install are: bamboo, book, brand , dots, flicking, gold, gold2, polaroid, polaroids, shadow, shells, slide, solid, notebook, wood.</li></ul>');
}

function _gallery_g2image_help() {
  return t('
    <h3>Gallery Image Assist (g2image)</h3>
    <p>Support for <a href="http://g2image.steffensenfamily.com">g2image</a> in either Standalone or TinyMCE is available to simplify adding images already in your Gallery2 albums into your Drupal nodes.</p>
    <p>Caution: By default, Drupal uses the \'Filtered HTML\' input format for adding content to the site and the default settings cause the &lt;img&gt; tags added by g2image to be removed. Check the TinyMCE documentation for instructions on how to avoid this.</p>');
}

?>
