'use strict';

module.exports = function (grunt) {

  grunt.initConfig({
    pkg: grunt.file.readJSON('package.json'),
    watch: {
      sass: {
        files: ['**/*.{scss,sass}'],
        tasks: ['sass', 'styleguide:dev', 'copy'],
        options: {
          livereload: true,
        }
      },
    },

    sass: {
      options: {
        sourceMap: true
      },
      dist: {
        files: {
          'css/style-sass.css': 'sass/app.scss'
        },
      }
    },
    styleguide: {
      dev: {
        options: {
          template: {
            src: 'styleguide/template/custom'
          },
          framework: {
            name: 'kss'
          }
        },
        files: {
          'styleguide/assets': 'sass/app.scss'
        }
      }
    },
    copy: {
      main: {
        files: [
          // includes files within path and its sub-directories
          {expand: true, src: ['sass/**'], dest: 'styleguide/assets/'},
          {expand: true, src: ['bootstrap-sass/**'], dest: 'styleguide/assets/'},
        ],
      },
    },
  });

  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-contrib-copy');
  grunt.loadNpmTasks('grunt-sass');
  grunt.loadNpmTasks('grunt-styleguide');

  grunt.registerTask('default', ['watch']);

};
