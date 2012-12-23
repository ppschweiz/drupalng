# Location of the theme's resources.
# Compass will overwrite the CSS files in the css_dir when set to watch.
css_dir = "css"
sass_dir = "sass"
images_dir = "images"
fonts_dir = "fonts"

#output_style = :expanded or :nested or :compact or :compressed
output_style = (environment == :production) ? :compressed : :expanded

line_comments = (environment == :development)

# To enable relative paths to assets via compass helper functions. Since Drupal
# themes can be installed in multiple locations, we don't need to worry about
# the absolute path to the theme from server root.
relative_assets = true

# Pass options to sass.
# - For production, we force the CSS to be regenerated even though the source
#   scss may not have changed, since we want the CSS to be compressed and have
#   the debug info removed.
sass_options = {:always_update => true} if (environment == :production)
