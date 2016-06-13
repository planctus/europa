/**
 * @file
 * Task for compiling sass sources.
 */

'use strict';

module.exports = function (grunt) {

  grunt.initConfig({
    pkg: grunt.file.readJSON('package.json'),
    watch: {
      sass: {
        files: ['css/*.{scss,sass}'],
        tasks: ['sass'],
        options: {
          livereload: true
        }
      }
    },

    sass: {
      dist: {
        files: {
          'css/style.css' : 'css/style.css.sass'
        }
      }
    },
  });

  grunt.loadNpmTasks('grunt-sass');
  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.registerTask('default', ['watch']);
};
