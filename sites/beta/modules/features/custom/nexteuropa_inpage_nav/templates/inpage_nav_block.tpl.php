<div class="inpage-nav">
    <nav class="navbar navbar-default navbar-fixed-top">
        <div class="container">
            <div class="navbar-header">
                <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target=".inpage-navigation--list" aria-expanded="false" aria-controls="navbar">
                    <span class="sr-only"><?php echo t("Toggle navigation"); ?></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                    <span class="icon-bar"></span>
                </button>
                <p class="navigation-place"><?php echo (isset($node_title) ? $node_title : ''); ?></p>
            </div>
            <div class="inpage-nav--list navbar-collapse collapse">
                <?php echo theme('item_list', $vars); ?>
            </div>
        </div>
    </nav>
</div>

