<?php
/**
 * @file
 * Template for in-page navigation.
 */
?>
<div class="inpage-nav">
    <nav class="navbar navbar-default navbar-fixed-top inpage-nav__navbar">
        <div class="container inpage-nav__container">
            <div class="navbar-header inpage-nav__header"  data-toggle="collapse" data-target="#inpage-navigation-list" aria-expanded="false" aria-controls="navbar">
                <button type="button" class="navbar-toggle collapsed inpage-nav__toggle">
                    <span class="sr-only"><?php print t("Toggle navigation"); ?></span>
                    <span class="inpage-nav__collapse-icon"></span>
                    <span class="inpage-nav__close-text"><?php print t("Close");?></span>
                </button>
                <span class="navbar-brand inpage-nav__help"><?php print t('On this page'); ?></span>
                <span class="navbar-brand inpage-nav__current"><?php print $title; ?></span>
            </div>
            <div class="navbar-collapse collapse inpage-nav__list" id="inpage-navigation-list">
              <span class="inpage-nav__title" ><?php print $title; ?></span>
                <?php print $links; ?>
            </div>
        </div>
    </nav>
</div>
