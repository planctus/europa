'use strict';

module.exports = function (grunt) {

  grunt.initConfig({
    pkg: grunt.file.readJSON('package.json'),
    watch: {
      sass: {
        files: ['**/*.{scss,sass}'],
        tasks: ['sass', 'kss', 'copy'],
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
    kss: {
      options: {
        template: 'styleguide/template/custom',
        css:      'css/style-sass.css'
      },
      dist: {
        files: {
          'styleguide/assets': ['sass']
        }
      }
    },
    copy: {
      main: {
        files: [
          // includes files within path and its sub-directories
          {expand: true, src: ['sass/**'], dest: 'styleguide/assets/'},
          {expand: true, src: ['bootstrap-sass/**'], dest: 'styleguide/assets/'},
          {expand: true, src: ['images/**'], dest: 'styleguide/assets/'},
          {expand: true, src: ['css/**'], dest: 'styleguide/assets/'},
        ],
      },
    },
  });

  grunt.loadNpmTasks('grunt-contrib-watch');
  grunt.loadNpmTasks('grunt-contrib-copy');
  grunt.loadNpmTasks('grunt-sass');
  grunt.loadNpmTasks('grunt-kss');

  grunt.registerTask('default', ['watch']);
  grunt.registerTask('styleguide', ['kss']);

};
